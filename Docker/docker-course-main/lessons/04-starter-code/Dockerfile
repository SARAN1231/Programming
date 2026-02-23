FROM python:3.8-slim
WORKDIR /src/app
COPY . .
RUN pip install -r grade-submission/requirements.txt
EXPOSE 3000
CMD [ "python","grade-submission/app.py" ]