# Adversarial Machine Learning: Defense Mechanisms Against Poisoning Attacks in Cybersecurity Models
- Fecha de publicacion: 2025

Poisoning atack is the most common adversarial ml.

Existen varias tecnicas para atacar un ML. La mas conocida o atacada es el envenenamiento en fase de entrenamiento. Donde se le dan datos erroneos sutilmente para que consuma como verdad al modelo asi de respuestas incorrectas incluso si el input es valido.

Dentro del ML Adversarial es un campo que se dedica a prevenir estos ataques, existen varias tecnicas pero no una unica solucion. Ademas los costes computacionales, la efectividad o la realizacion de estas defensas es muy alta, solo se realizan simulaciones o no son efectivas al 100%.

Ocurre tambien que el modelo realiza mucho esfuerzo perdiendo correctividad en la ofuscacion de datos privados.

No hay un sistema unico, estandar con el cual seguir y proteger de estos ataques.

En el ambito de la ciberseguridad se depende mucho del ML, entonces es importante analizar como entiende y responde a los diferentes problemas que debe sortear. Ese es el objetivo del paper. Analizar las tecnicas existentes, entendiendo antes los riesgos y la importancia de que haga las cosas bien, como actuan y ver cuan efectivo y factible es realmente.
 
### Que es entonces AML?
Es un area de estudio sobre las vulnerabilidades que tienen o pueden tener los modelos de ML que luego pueden ser utilizados en IA. Esto se hace dandole un adversarial example, un ejemplo adversarial de algo incorrecto y entrenarlo para que sepa que es verdad, de esa forma estamos envenenando la base de conocimiento del modelo.

El centro es la alta susceptibilidad que tienen estos modelos y lo fragil que son.

Los tipos de ataques se clasifican segun en que parte del proceso del ML se aplican. Los ataques de envenenamiento ocurren en la etapa de entrenamiento y causan mas problemas en modelos hechos para ciberseguridad porque involucran esa inyeccion de datos maliciosos en el set de entrenamiento.

> Inference-time attack son otro tipo de ataque.

Los poisoning attack son importantes en ciberseguridad porque al ocurrir en fase de entrenamiento significa que el sistema de deteccion de intrusos no detecto cambios, no alerto entonces el modelo es susceptible a tomar informacion erronea como verdad, crear conexiones erroneas sin que nadie note nada, la dificultad en trazar y encontrar el error tambien es grande.

Sistemas como detectores de spam, de fraude, en medicina es vital que la informacion sea minuciosa y correcta, un pequenio error puede agravar mucho la situacion.

### Como nos defendemos?

- Sanitizacion de datos: 
- Entrenamiento adversarial: 
- Privacidad diferenciada: 
- Ensemble learning approaches
- Federated learning
- Tecnicas de deteccion de anomalias


# Adversarial Machine Learning for Cyber security Defense: Detecting Model Evasion, Poisoning Attacks, and Enhancing the Robustness of AI Systems
- Fecha de publicacion: 2025

Habla al parecer solamente del tipo de defensa Adversarial training. Pros contras

# Adversarial Threats to AI-Driven Systems: Exploring the Attack Surface of Machine Learning Models and Countermeasures
- Fecha de publicacion: 2025

Habla del peligro de los ataques adversariales y muestra tecnicas de defensa basadas en mitre atlas y cifar-10 de ibm para determinar la probabilidad de ataque hacia un determinado modelo. Son datasets de prueba


# Evasion and Manipulation Risks in AI-Powered Intrusion Detection Systems: Exposing Vulnerabilities and Building Resilient Defenses
- Fecha de publicacion: 2024

Nos cuenta como las tecnologias que usan usan ML o Deep Learning que se usan para crear IDS son potencialmente manipulables y por la sensibilidad del contexto pueden hacer mucho danio.


# How Deep Learning Sees the World: A Survey on Adversarial Attacks & Defenses
- Fecha de publicacion: 2024

Tres grandes peligros: Self-driving Vehicles, Malware Detection, and Healthcare.


# EXPLAINING AND HARNESSING ADVERSARIAL EXAMPLES
- Fecha de publicacion: 2015

Este se centra en minimizar los adversarial examples. Habla de que esta en la naturaleza de los ML tener errores o confundirse con las respuestas porque los set de entrenamientos son muy generales y causa ese proceso de adivinacion que deben sortear los modelos.
Por ello, asumo que su principal defensa es el adversarial training y como mejorar el input o los examples para que sean minimos.
O quizas como dice harnessing es para que tengan a estos adversarial examples como anclas y los tengan presentes siempre que respondan, lo que explicaria la alta demanda computacional que tienen.

# Preguntas 
- Que otros tipos de ataques existen?