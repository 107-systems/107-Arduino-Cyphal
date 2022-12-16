FROM ubuntu:latest

# set a directory for the app
WORKDIR /usr/src/app

# install dependencies
RUN apt-get update -y
RUN apt-get install -y apt-utils
RUN apt-get install -y locales
RUN apt-get install -yq tzdata
RUN echo "Europe/Berlin" > /etc/timezone && \
    touch /etc/locale.gen && \
    dpkg-reconfigure -f noninteractive tzdata && \
    sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen && \
    echo 'LANG="de_DE.UTF-8"'>/etc/default/locale && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=de_DE.UTF-8

ENV LANG de_DE.UTF-8
ENV LANGUAGE de_DE.UTF-8
ENV LC_ALL de_DE.UTF-8

RUN apt-get install -y bash
RUN apt-get install -y git
RUN apt-get install -y python3-pip
RUN pip3 install nunavut

CMD ["/bin/bash", "-c", "cd /107-Arduino-Cyphal; ./extras/script/update_c_header.sh; exit"]
