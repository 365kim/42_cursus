# ft_server

### :bulb: Evaluation Log
1. 20/08/23 : OK
    - **100 score**
---

### :bulb: Objective
- to discover `Docker` and install a complete web server, which will run multiple services including Wordepress, phpMyAdmin, and a SQL database..
- to learn about `system administration`.
---

### :bulb: Files Turned In
1. Mandatory Part
    - [__Dockerfile__ ](./Dockerfile)
    - __srcs/__
        - [__init.sh__](./srcs/init.sh)
        - [__nginx.conf__](./srcs/nginx.conf)
        - [__phpMyAdmin-4.9.0.1.tar.gz__](./srcs/phpMyAdmin-4.9.0.1.tar.gz)
        - [__config.inc.php__](./srcs/config.inc.php)
        - [__wordpress-5.4.1.tar.gz__](./srcs/wordpress-5.4.1.tar.gz)
        - [__wp-config.php__](./srcs/wp-config.php)
        - [__theme.tar.gz__](./srcs/theme.tar.gz) _(not necessary)_

2. Bonus Part: N/A

---
### :bulb: Check if...
- all the necessary configuration files of the server are in the folder __srcs__.
- the __Dockerfile__ is at the root of the repository.
- you can run the `docker build .` command.
- the you have only one container, which is built with __Debian Buster__.
- you can run the container with `docker run xxx` without problems.
- __Nginx__ uses the __SSL protocol__.
- the server __redirects__ to the correct website, according to the url.
- the server runs multiple services __(WordPress and phpMyAdmin)__.
- the server is running with an __autoindex__ which can be deactivated when the container is launched (via an environment variable for example).
- the WordPress website runs entirely with the MySQL database. You can __go to the site, log in, and watch the database__.
- the SQL database works with phpMyAdmin. You should see the WordPress __tables and data__.

---
### :bulb: Useful Links
- [Dockerfile reference](https://docs.docker.com/engine/reference/builder/) _(official)_
- [Docker run reference](https://docs.docker.com/engine/reference/run/#expose-incoming-ports) _(official)_
- [Best practices for writing Dockerfiles](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/) _(official)_
- [nginx config file structure](https://nginx.org/en/docs/beginners_guide.html#conf_structure) _(official)_
- [autoindex_module](http://nginx.org/en/docs/http/ngx_http_autoindex_module.html) _(official)_
- [How to create a self-signed certificate with openssl](https://stackoverflow.com/questions/10175812/how-to-create-a-self-signed-certificate-with-openssl) 
