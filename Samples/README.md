Please follow these instruction to properlly install Revtwo snap example. 

If you did not installed snapcraft and snap on your machine, please install it using following terminal commands:
sudo apt install snapcraft
sudo apt install snap  
sudo snap install core 

Revtwo currently provides four samples how LinuxAgent could be run within the snap as part: 
1. Run and terminate with consumer (LinuxAgent will be run together with consumer application and terminate when consumer application exit)
2. Run bot not terminate with consumer (LinuxAgent will be run together with consumer application but note terminate when consumer application exit)
3. Run on demand (LinuxAgent will be run on demand)
4. Run as daemon (LinuxAgent will be run as daemon)

After downloading Revtwo Samples directory, navigate to desired sample from Samples directory.
For example: cd Samples/demo-run-and-terminate-with-consumer/

Now issue folowing terminal commands from desired sample directory. 
sudo snapcraft 
snap install rev2agent-part-test_0.1_amd64.snap --devmode 

Please copy userconfig.json file and appconfig.data file to /var/snap/rev2agent-part-test/common/ ($SNAP_COMMON directory).
userconfig.json file must contain "device_name" and "uuid" parameters. 

In case of using run-as-daemon example, please restart you machine. LinuxAgent application will be run automatically after system boots. 

