#!/usr/bin/python3
''' run_cmd.py '''

import subprocess
import json
import base64

cmds = [
        "rpm -q -a",
        "df -h",
        "mount",
        "ls -l-",
        "free -m",
        "dmesg",
        "netstat -t -a -u -n -p"
       ]

def run_cmd(cmd):
    ''' def run_cmd(cmd): '''

    result = subprocess.run(cmd, capture_output=True, text=True)

    my_dict = {
                "name" : ''.join(result.args), \
                "args" : result.args, \
                "returncode": result.returncode, \
                "stdout": base64.b64encode(result.stdout.encode("ascii")).decode("ascii"), \
                "stderr": base64.b64encode(result.stderr.encode("ascii")).decode("ascii"), \
              }
    json_string = json.dumps(my_dict)
    print(json_string, end = '')

if __name__ == '__main__':
    print("{ \"cmd_details\": [ ")

    for count, line in enumerate(cmds):

        ## split line string into list
        my_list = line.split()
        run_cmd(my_list)

        ## make sure we output valid JSON
        if count != (len(cmds)-1):
            print(",")

    print("] }")
