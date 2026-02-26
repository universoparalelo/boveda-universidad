> Metasploit es un proyecto de código abierto para la seguridad informática, que proporciona información acerca de vulnerabilidades de seguridad y ayuda en tests de penetración "Pentesting" y el desarrollo de firmas para sistemas de detección de intrusos.

*Metasploit* incluye muchas herramientas:
- msfconsole
- msfvenom
- msfdb
- etc.

## Install 
- [Link](https://docs.rapid7.com/metasploit/installing-the-metasploit-framework/)
```
curl https://raw.githubusercontent.com/rapid7/metasploit-omnibus/master/config/templates/metasploit-framework-wrappers/msfupdate.erb > msfinstall && chmod 755 msfinstall && ./msfinstall

./msfconsole
# yes
```

To check to see if the database was set up, run the following command:
`$ db_status`