### 0. Fulfill prerequisites
#      - Double check whether Docker Desktop is running.
#      - Start evaluation from the ft_server directory.

name_of_image="coffee"
name_of_container="sleep"



### 1. Build an image from a 'Dockerfile' using the current directory as context
#      -t, --tag list                Name and optionally a tag in the 'name:tag' format

docker build -t ${name_of_image} .



### 2. Run a command in a new container
#      --name string                Assign a name to the container
#      --rm      		              Automatically remove the container when it exits
#      -i, --interactive            Keep STDIN open even if not attached
#      -t, --tty                    Allocate a pseudo-TTY
#      -p, --publish list           Publish a container's port(s) to the host

docker run --name ${name_of_container} --rm -it -p 80:80/tcp -p 80:80/udp -p 443:443/tcp -p 443:443/udp ${name_of_image}
