Please use the following instructions to properly run the Agent application. 

The Application can be run from following environments: 
- As standalone 
- Within docker 
- As snap 

In case of Agent standalone, follow instructions to properly run Agent: 
- Clone this repository to your local machine 
- Copy downloaded appconfig.data from revtwo webpage to AgentStandalone directory (For example: sudo cp ~/Downloads/appconfig.data ~/linux-agent/AgentStandalone) 
- Generate userconfig file by issuing following command inside AgentStandalone directory (sudo python generateConfig.py)
Userconfig file can be made manually. Must be in *.json format and must contain "uuid" and "device_name" fields. 

In case of Agent within docker, follow these instructions to properly run Agent: 
- Download docker issuing folowing command from terminal: wget -qO- https://get.docker.com/ | sh 
- Create container issuing folowing command: docker run --network=host --name rev2agent -itd ubuntu 
- Generate userconfig.json file and copy appconfig.data file as described in previous case 
- Copy AgentStandalone folder to container: docker cp AgentStandalone/ rev2agent:/
- Attach docker to run Iotagent: docker attach iotagent 
- Navigate to AgentStandalone folder and run agent 

In case of Agent as Snap, do the next: 
- Install Agent from public snap repository (snap install rev2agent) 
- Copy appconfig.data to /var/snap/rev2agent/common (For example: sudo cp ~/Downloads/appconfig.data /var/snap/rev2agent/common) 
- Generate userconfig file issuing folowing command from terminal: sudo rev2agent.generate-user-config
- Run rev2agent issuing folowing command from terminal: rev2agent