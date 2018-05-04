#! /usr/bin/env python
import mysql.connector
import time
today=int(time.time())
try:
	cnx = mysql.connector.connect(option_files='connector.cnf')
except mysql.connector.Error as err:
	print(err)
cursor = cnx.cursor()
cursor.execute("INSERT INTO Lumivahti "
		"(time, depth, temperature)"
		"VALUES (" + str(today) + ", 5, -15)")
cnx.commit()

cursor.close()
cnx.close()
