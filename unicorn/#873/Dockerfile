FROM ubuntu:16.04

RUN apt-get update && env DEBIAN_FRONTEND=readline apt-get install -yy python python-pip  && apt-get clean
RUN pip install unicorn
ADD . /src
WORKDIR /src
CMD python2 none-type-error.py
