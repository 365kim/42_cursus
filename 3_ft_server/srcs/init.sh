#!/bin/bash

service mysql start

chown -R www-data /var/www/*
chmod -R 755 /var/www/*


ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
rm -rf /etc/nginx/sites-enabled/default


mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
			-subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=cadet/CN=localhost" \
			-out /etc/nginx/ssl/localhost.pem \
			-keyout /etc/nginx/ssl/localhost.key


echo "CREATE DATABASE wordpress;" \
		| mysql -u root --skip-password
echo "UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user='root';" \
		| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* to 'root'@'localhost';" \
		| mysql -u root --skip-password
echo "FLUSH PRIVILEGES" \
		| mysql -u root --skip-password


path="/var/www/localhost"

mkdir ${path}
tar -xvf phpMyAdmin-4.9.0.1.tar.gz
mv -f phpMyAdmin-4.9.0.1 ${path}/phpmyadmin
mv /var/config.inc.php ${path}/phpmyadmin/

tar -xvf wordpress-5.4.1.tar.gz
mv -f wordpress/ ${path}
mv /var/wp-config.php ${path}/wordpress

tar -xvf theme.tar.gz
mv -f theme/ etc/nginx/theme
rm *.tar.gz

service php7.3-fpm start
service nginx start

bash
