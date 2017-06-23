#! /usr/bin/env python3.5
import json
import uuid
import string
import os
import socket
import sys

#determine userconfig path
configpath = os.getcwd() + "/userconfig.json"

#prepare json data for userconfig file

#UUID format: ac6996a9-asdf-4fe8-8dfe-22d2e5a76d2e
#create UUID using uuid lib
uuid = str(uuid.uuid4())

#determine device name
device_name = socket.gethostname()

data = {}
data["uuid"] = uuid
data["device_name"] = device_name

#check is sudo. needed for file creation (w+)
if os.getuid() != 0:
    print("Please execute as sudo. Needed for file creation.")
    sys.exit()
    
with open(configpath, "w+") as jsonFile:
    jsonFile.write(json.dumps(data, indent=4, separators=(',', ': ')))
    print ("Config file created successfully.")