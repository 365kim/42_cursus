FROM    debian:buster

LABEL   maintainer="mihykim@student.42seoul.kr"

RUN    	apt-get update && apt-get install -y \
    	nginx \
    	mariadb-server \
    	php-fpm \
    	php-mysql \
    	php-cli \
    	php-mbstring \
    	openssl \
    	vim

COPY    srcs/nginx.conf /etc/nginx/sites-available/localhost
COPY    srcs/config.inc.php /var
COPY    srcs/wp-config.php /var
COPY    srcs/phpMyAdmin-4.9.0.1.tar.gz ./
COPY    srcs/wordpress-5.4.1.tar.gz ./
COPY    srcs/init.sh ./
COPY    srcs/theme.tar.gz ./

EXPOSE  80 443

CMD    	bash init.sh


#### Description
#
# 0. Dockerfile
#    - Docker will run instructions above in order
#    - Comment lines that begin with # are removed before the Dockerfile instructions are executed
#
# 1. FROM
#    - a valid Dockerfile must start with a FROM instruction.
#    - initializes a new build stage and sets the Base Image for subsequent instructions.
#
# 2. LABEL
#    - adds metadata to an image.
#    - replaces the deprecated instruction MAINTAINER.
#    - to view labels, use the `docker image inspect` command.
#
# 3. RUN
#    - executes commands in a new layer on top of the current image and commit the results
#    - backslash(\) can be used to continue a single RUN instruction onto the next line.
#    - Always combine RUN apt-get update with apt-get install in the same RUN statement to avoid caching issues.
#
# 4. COPY
#    - adds files from your Docker client’s specified directory.
#
# 5. EXPOSE
#    - informs Docker that the container listens on the specified network ports at runtime.
#    - regardless of EXPOSE settings, you can override them at runtime by using -p flag as like `docker run -p 80:80/tcp -p 80:80/udp ...`.
#
# 6. CMD
#    - sets the command to be executed when running the image.
#    - does not execute anything at build time, while while RUN actually runs a command and commits the result.
#    - if there are more than one CMD in a Dockerfile, only the last one will be effective.
#
# Source : https://docs.docker.com/engine/reference/builder/
