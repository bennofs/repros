#!/usr/bin/env bash
echo ":: building docker image"
image=$(docker build -q .)
echo ":: running"
exec docker run "$image"
