Please follow these instruction to properly install Revtwo snap example. 

# Snap Installation 
If you don't have snapcraft and snap installed, please do it running the following commands in the terminal:<br />
```sh
sudo apt install snapcraft
sudo apt install snap
sudo snap install core
```

# RevTwo Snap Samples
RevTwo currently provides four samples as a showcase of how the LinuxAgent could be run as "part" inside the snap:<br />
1. Start and terminate with the consumer (LinuxAgent will start and terminate together with the consumer application)
2. Start but don't terminate with consumer (LinuxAgent will start together with the consumer application but won't terminate even after the consumer application exits)
3. Start on demand (LinuxAgent will start on demand)
4. Start as daemon (LinuxAgent will start as daemon)

After downloading Revtwo Samples directory, navigate to desired sample from Samples directory.<br />
For example: 
```sh
cd Samples/demo-run-and-terminate-with-consumer/
```
Now issue folowing terminal commands from desired sample directory.<br />
```sh
sudo snapcraft
sudo snap install rev2agent-part-test_0.1_amd64.snap --devmode
```
Please copy userconfig.json file and appconfig.data file to /var/snap/rev2agent-part-test/common/ ($SNAP_COMMON directory).<br />
userconfig.json file must contain "device_name" and "uuid" parameters. 

In case of using run-as-daemon example, please restart you machine. LinuxAgent application will be run automatically after system boots. 

