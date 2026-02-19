> **arp-scan** is a command-line network scanning tool that uses the **Address Resolution Protocol (ARP)** to discover active devices on a local network.

- To scan your local network:
```
sudo arp-scan --localnet
```
This scans all IP addresses on the subnet connected to your default interface. 

- For a specific range:
```
sudo arp-scan 192.168.1.0/24
```

- Specify interface explicitly:
```
sudo arp-scan -I eth0 192.168.1.0/24
```
### Advanced Options
- `--srcaddr=DE:AD:BE:EF:CA:FE`: Use a custom source MAC address.
- `--bandwidth=512000`: Increase scan speed (use cautiously to avoid network disruption).
- `--retry=2`: Retry unanswered packets.
- `arp-fingerprint`: Use with `arp-scan` to fingerprint operating systems based on ARP behavior. 

> ⚠️ **Note**: Requires **root privileges** or `SUID root` permissions to access raw network interfaces.  ARP is **non-routable**, so scanning is limited to the local subnet. 
### Installation
- On Debian/Ubuntu/Kali:
```
sudo apt install arp-scan
```
