#!/usr/bin/python
import sys
import logging
logging.basicConfig(stream=sys.stderr)
sys.path.insert(0,"/home/lumivahti/public_html/lumivahtihtml")

from lumivahtihtml import app as application
