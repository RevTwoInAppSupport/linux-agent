# Revtwo Linux Agent 
Linux is the preferred operating system for embedded systems such as Internet of Things, as well as servers and general computing (actually almost everything that isn’t a personal computer or phone). As Linux is built into even more products, they will account for millions to billions of embedded computers. Many of these will need a way to provide remote support in a cost effective way.

RevTwo has an agent for Linux devices that provides quick, secure remote access for helpdesk or technical people.
## Installation  
Agent support Desktop and ARMHF architecture. 
Depending on your dependencies and library version, choose coresponding release version. 

For example if you use Ubuntu Linux 16.06, choose Desktop gcc-5.4 version. 
If you use Raspberry Pi Raspbian OS, choose ARMHF gcc-4.9.3 version. 
.
The Application can be run from following environments: 
- As standalone 
- Within docker 
- As snap 
- As snap part

### Agent standalone 
In case of Agent standalone, follow instructions to properly run Agent.

1. Clone this repository to your local machine:
```sh
$ cd ~
$ git clone https://github.com/RevTwoInAppSupport/linux-agent.git
```
2. Navigate to Agent standalone directory. _(Choose your arch and compiler version)_
```sh
$ cd  ~/linux-agent/AgentStandalone/Desktop/gcc-5.4
```
2. Copy downloaded appconfig.data from revtwo webpage to preffered AgentStandalone directory.
For example: 
```sh
$ cp ~/Downloads/appconfig.data .
```
3. Generate userconfig file by issuing following command inside AgentStandalone directory. For example: 
```sh
$ sudo python generateConfig.py
```
For more detailed userconfig.json file, reffer to Advance agent configuration. 

4. Run agent 
```sh
$ ./R2Agent
```

### Agent inside docker
In case of Agent within docker, follow these steps to properly run Agent: 
1. Download docker issuing folowing command:
```sh
$ wget -qO- https://get.docker.com/ | sh 
```

2. Create container issuing folowing command:
```sh
$ docker run --network=host --name rev2agent -itd ubuntu 
```
3. Generate userconfig.json file and copy appconfig.data file as described in previous case 
 ```sh
cp ~/Downloads/appconfig.data ~/linux-agent/AgentStandalone/Desktop/gcc-5.4 
$ sudo python generateConfig.py
```
4. Copy AgentStandalone folder to container:
```sh
$ docker cp AgentStandalone/Desktop/gcc-5.4 rev2agent:/
```
5. Attach docker to run Iotagent:
```sh
$ docker attach iotagent 
```
6. Navigate to AgentStandalone folder and run agent 
### Agent as snap
In case of Agent as Snap, do the next: 
1. Install Agent from public snap repository
```sh
$ snap install rev2agent
```
2. Copy appconfig.data to /var/snap/rev2agent/common. For example: 
```sh
$ cp ~/Downloads/appconfig.data /var/snap/rev2agent/common
 ```
3. Generate userconfig file issuing folowing command from terminal:
```sh
$ sudo rev2agent.generate-user-config
 ```
4. Run rev2agent issuing folowing command from terminal:
```sh
$ rev2agent
 ```
 ### Agent as snap part 
 Agent can be launched as snap part together with your application. 
 Please see provided examples on this [LINK](https://github.com/RevTwoInAppSupport/linux-agent/tree/master/Samples). 

 ## Advanced agent configuration 
 The RevTwo linux agent requires configuration to run. This has 2 parts, one for the model of the device, and one for the instance of the device. The path to configuration files is an argument to the agent, so running
 ```sh
 $ R2Agent ~/rev2agent/config
  ```
  will tell the agent to look in the current directory (default) and then in the specified directory for these files.

The first configuration is called appconfig.data and it contains the model of the agent. You get this file from the Models page of the web application.
<img src="http://revtwo.com/docs/wp-content/uploads/2017/04/linux_appconfig.png" width="30%"></img>

This file is encrypted but still text. If you need to transfer this file to a linux target, the text can be pasted into an editor.

The second file is called userconfig.json and this contains the instance identity for the device.  Here is an example of the minimal file:
 ```sh
{
"uuid"          : "ac6996a9-dee7-33da-8dfe-22d2e5a76d2e",
"device_name"   : "S84T-9182",
}
  ```
  
  The uuid must be a globally unique string that identifies the device for its lifetime.

The device_name can be any string that identifies the device to your users, or application. The recommendation is to use a serial number for a product. This string should be unique within your model or searches will not be able to find the single device.


The following are optional:
- The app_name is only used if syslog_addr is specified, and the syslog entries will be organized under the app_name.
- The revtwodb_path is a path to a file that contains logging and other information. _Details coming soon_
- The syslog_addr is the IP address of a syslog server where the agent will send messages when a session is connected.
- The log_to is the path to a directory that will contain log files that record remote sessions.
- The log_level specifies how much logging to do. Values are: “trace”, “debug”, “warning”, and “error” in ascending order. Only message of log_level and higher will be generated by the agent.
- TODO tuneling

An example of a full userconfig.json file is:
 ```sh
{
"uuid"          : "ac6996a9-dee7-33da-8dfe-22d2e5a76d2e",
"device_name"   : "S84T-9182",
"revtwodb_path" : "./revtwo.db",
"syslog_addr"   : "192.168.2.36",
"app_name"      : "R2Agent",
"log_level"     : "warning",
"log_to"        : "./logs"
TODO tuneling
}
  ```