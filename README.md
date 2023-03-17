sudo npm install -g @asyncapi/cli

npm install @asyncapi/generator 

npm install @asyncapi/html-template 

asyncapi generate fromTemplate edscorbot-async-api.yaml @asyncapi/html-template -o docs

parameters to template: https://www.asyncapi.com/docs/tools/generator/usage