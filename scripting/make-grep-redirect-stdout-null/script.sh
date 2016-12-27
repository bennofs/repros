#!/usr/bin/env bash

exec nix-shell --pure -p gnumake gnugrep -I nixpkgs=https://github.com/NixOS/nixpkgs/archive/3b050791e47362cb4d6ce4da74bbaa360eaa8ff3.tar.gz  --command "make all > /dev/null"
