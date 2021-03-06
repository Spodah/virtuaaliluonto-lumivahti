#! /usr/bin/env python
import mysql.connector
from mysql.connector import errorcode
from flask import Flask, render_template, jsonify, json, request

app = Flask(__name__)

@app.route("/")
def main():
	return render_template("index.html")

@app.route("/data")
def getData():
	try:
		cnx = mysql.connector.connect(option_files='connector.cnf')
	except mysql.connector.Error as err:
		print(err)
	cursor = cnx.cursor()

	cursor.execute('''SELECT * FROM Lumivahti ORDER BY time DESC LIMIT 1;''')

	columns = cursor.column_names
	datarows = cursor.fetchall()
	datalist = datarows[0]
	dicta = dict(zip(columns, datalist))
	rows = jsonify(dicta)
	print rows

	cursor.close()
	cnx.close()

	return rows

if __name__ == "__main__":
	app.run()
