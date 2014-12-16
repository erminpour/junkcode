#!/usr/bin/python -tt

import atexit
import paramiko


class MySSH:

    def __init__(self, host, user, password, port=22):
        client = paramiko.SSHClient()
        client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        client.load_system_host_keys()
        client.connect(host, port=port, username=user, password=password)
        atexit.register(client.close)
        self.client = client

    def __call__(self, command):
        stdin, stdout, stderr = self.client.exec_command(command)
        sshdata = stdout.readlines()
        for line in sshdata:
            print(line)

remote = MySSH('10.0.135.42', 'username', 'password')
remote('uname -a')
remote('whoami')
