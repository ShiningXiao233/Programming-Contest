import subprocess
import time
import sys


def exec_cmd(info : str, cmd : str):
    cmd_list = list(cmd.split(' '))
    # print(cmd_list)
    rp = subprocess.run(cmd_list, capture_output=True, encoding='utf-8')
    print(info, rp.returncode == 0, rp.stdout)
    if rp.returncode != 0:
        print(rp.stderr)
        exit(0)

if __name__ == '__main__':
    exec_cmd("pull", "git pull")
    exec_cmd("add", "git add .")
    if (len(sys.argv) > 1):
        info = sys.argv[1]
    else:
        info = time.strftime("%Y-%m-%d-%H:%M:%S", time.localtime())
    exec_cmd("commit", f"git commit -m {info}")
    exec_cmd("push", "git push")