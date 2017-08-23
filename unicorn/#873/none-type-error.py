#!/usr/bin/env python2
from unicorn import *
from unicorn.x86_const import *
import sys
from pprint import pprint
import os
path = os.path.abspath(os.path.dirname(__file__))

sys.path = [path]
import angr.state_plugins.unicorn_engine
angr.state_plugins.unicorn_engine._unicorn_tls = Uc(UC_ARCH_X86, UC_MODE_32)
