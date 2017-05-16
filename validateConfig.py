#! /usr/bin/env python3.5
import json
import os
import sys

#BE CAREFUL: json overwrites duplicate key by the latter one!!!

mandatoryKeys = ["uuid", "device_name"]
optionalKeys = ["channel", "log_level", "log_to", "revtwodb_path", "app_name", "syslog_addr"]
def genericFileValidation (data):
    if (len(data) < len(mandatoryKeys)) or (len(mandatoryKeys) + len(optionalKeys) < len(data)):
        print ("ERROR: Number of keys in file is different than expected range")
        sys.exit(100)
    for key in mandatoryKeys:
        if key not in data:
            print ("ERROR! Key value " + key + " not provided")
            sys.exit(100)
    for key in data:
        if (key not in mandatoryKeys) and (key not in optionalKeys):
            print ("ERROR! Key value " + key + " not supported")
            sys.exit(100)
        elif data[key] == "":
            print ("ERROR! Value for " + key + " is blank")
            sys.exit(100)
        elif data[key] == "null" or data[key] == None:
            print ("ERROR! Value for " + key + " is null")
            sys.exit(100)

print ("INFO: Verifying userconfig requirements")
configname = "userconfig.json"
configpath = ""

if os.path.isfile(configname):
    configpath = configname
    print ("INFO: Userconfig found in local folder")
elif os.path.isfile(str(os.environ["SNAP_DATA"]) + "/" + configname):
    print ("INFO: Userconfig found in SNAP_DATA folder")
    configpath = str(os.environ["SNAP_DATA"]) + "/" + configname
else:
    print ("ERROR: Userconfig not found aborting")
    sys.exit(100)

with open(configpath) as jsonFile:
    try:
        data = json.load(jsonFile)
    except Exception:
        print ("ERROR: File is not in valid json format")
        sys.exit(100)

genericFileValidation(data)
if "log_to" in data:
    try:
        os.makedirs(data["log_to"])
        os.chmod(data["log_to"], 0o777) #give full permissions
    except os.error:
        print ("WARNING: Missing privileges to create log folder on the specified location. Please use another location. Using default location instead")
        del data["log_to"]

print ("INFO: Userconfig passed validation")
