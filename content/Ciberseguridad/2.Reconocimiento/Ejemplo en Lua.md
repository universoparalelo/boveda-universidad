- **example.nse**
```lua
--HEAD--

description = [(Script que ennumera y reporta puertos abiertos por tcp)]

--RULES--
portrule = function(host, port)
	return port.protocol == "TCP"
		and port.state == "open"
end
	
--ACTION--
action = function(host, port)
	return "This port is open"
end
```

Para ejecutarlo
```bash
nmap --script /toda_la_ruta/example.nse -p22,80 ip_address
```