`sudo apt install wpscan`

## Usage
`wpscan --url https://127.0.0.1:31337 -e vp,u`
Dentro de la web de wpscan, con una cuenta, Profile > Token.
`wpscan --url https://127.0.0.1:31337 -e vp --api-token="api-token"`

### Fuerza bruta
`wpscan --url https://127.0.0.1:31337 -U savitar -P usr/share/wordlist/rockyou.txt`