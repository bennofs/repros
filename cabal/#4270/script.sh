#!/usr/bin/env bash

cabal clean
cabal configure --enable-tests --enable-executable-dynamic
cabal test
