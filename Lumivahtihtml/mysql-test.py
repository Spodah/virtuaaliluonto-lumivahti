import mysql.connector
from datetime import time, datetime
today="""'"""+datetime.now().strftime('%H:%M:%S')+"""'"""
try:
	cnx = mysql.connector.connect(option_files='connector.cnf')
except mysql.connector.Error as err:
	print(err)
cursor = cnx.cursor()
cursor.execute("INSERT INTO Lumivahti "
		"(time, depth, temperature)"
		"VALUES (" + today + ", 5, -15)")
cnx.commit()

cursor.close()
cnx.close()
