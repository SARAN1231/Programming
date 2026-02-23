from flask import Flask, render_template, request, redirect, url_for
import mysql.connector
import os
import uuid
import time

app = Flask(__name__)

# Database configuration using environment variables
db_config = {
    'host': os.getenv('DATABASE_HOST', 'mysql'),
    'user': os.getenv('DATABASE_USER', 'user'),
    'password': os.getenv('DATABASE_PASSWORD', 'password'),
    'database': os.getenv('DATABASE_NAME', 'db')
}

print("LOADED DB CONFIG:", db_config)

def create_grades_table(retries=10, delay=3):
    for attempt in range(retries):
        try:
            print(f"Attempting DB connection ({attempt+1}/{retries})...")
            conn = mysql.connector.connect(**db_config)
            cursor = conn.cursor()
            cursor.execute('''
                CREATE TABLE IF NOT EXISTS grades (
                    id VARCHAR(255) PRIMARY KEY,
                    name VARCHAR(255),
                    subject VARCHAR(255),
                    score VARCHAR(10)
                )
            ''')
            conn.commit()
            cursor.close()
            conn.close()
            print("Database initialized successfully")
            return
        except mysql.connector.Error as err:
            print("Database connection failed:", err)
            time.sleep(delay)

    print("❌ Failed to connect to MySQL after several attempts.")
    exit(1)

create_grades_table()

class Grade:
    def __init__(self, name=None, subject=None, score=None, id=None):
        self.name = name
        self.subject = subject
        self.score = score
        self.id = id

    def save_to_db(self):
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()

        if self.id:  
            # Update if ID exists
            cursor.execute("UPDATE grades SET name=%s, subject=%s, score=%s WHERE id=%s",
                           (self.name, self.subject, self.score, self.id))
        else:
            # Insert new record
            self.id = str(uuid.uuid4())
            cursor.execute("INSERT INTO grades (id, name, subject, score) VALUES (%s, %s, %s, %s)",
                           (self.id, self.name, self.subject, self.score))

        conn.commit()
        cursor.close()
        conn.close()

    @staticmethod
    def get_all_grades():
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()
        cursor.execute("SELECT id, name, subject, score FROM grades")
        grades = [Grade(id=row[0], name=row[1], subject=row[2], score=row[3]) for row in cursor.fetchall()]
        cursor.close()
        conn.close()
        return grades

    @staticmethod
    def get_grade_by_id(gid):
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()
        cursor.execute("SELECT id, name, subject, score FROM grades WHERE id=%s", (gid,))
        row = cursor.fetchone()
        cursor.close()
        conn.close()
        return Grade(id=row[0], name=row[1], subject=row[2], score=row[3]) if row else None

@app.route('/', methods=['GET'])
def get_form():
    gid = request.args.get('id')
    grade = Grade.get_grade_by_id(gid) if gid else Grade()
    return render_template('form.html', grade=grade)

@app.route('/handleSubmit', methods=['POST'])
def submit_form():
    form_data = request.form
    grade = Grade(
        name=form_data['name'],
        subject=form_data['subject'],
        score=form_data['score'],
        id=form_data.get('id') or None
    )
    grade.save_to_db()
    return redirect(url_for('get_grades'))

@app.route('/grades', methods=['GET'])
def get_grades():
    return render_template('grades.html', grades=Grade.get_all_grades())

if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0', port=8080)
