Please follow these instruction to properly install Revtwo snap example. 

If you don't have snapcraft and snap installed, please do it running the following commands in the terminal:<br />
sudo apt install snapcraft<br />
sudo apt install snap<br />
sudo snap install core<br />

RevTwo currently provides four samples as a showcase of how the LinuxAgent could be run as "part" inside the snap:<br />
1. Start and terminate with the consumer (LinuxAgent will start and terminate together with the consumer application)
2. Start but don't terminate with consumer (LinuxAgent will start together with the consumer application but won't terminate even after the consumer application exits)
3. Start on demand (LinuxAgent will start on demand)
4. Start as daemon (LinuxAgent will start as daemon)

After downloading Revtwo Samples directory, navigate to desired sample from Samples directory.<br />
For example: cd Samples/demo-run-and-terminate-with-consumer/

Now issue folowing terminal commands from desired sample directory.<br />
sudo snapcraft<br />
sudo snap install rev2agent-part-test_0.1_amd64.snap --devmode<br />

Please copy userconfig.json file and appconfig.data file to /var/snap/rev2agent-part-test/common/ ($SNAP_COMMON directory).<br />
userconfig.json file must contain "device_name" and "uuid" parameters. 

In case of using run-as-daemon example, please restart you machine. LinuxAgent application will be run automatically after system boots. 

