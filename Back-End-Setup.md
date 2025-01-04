# Backend Server Setup

This guide provides step-by-step instructions and npm commands to set up a backend server project using Node.js, Express, MongoDB, and other essential tools.

---

## 🚀 Prerequisites
- Ensure Node.js and npm are installed on your machine. You can download them from [Node.js Official Website](https://nodejs.org/).
- Verify installation:
  ```bash
  node -v
  npm -v
  ```

---

## 🛠️ Project Initialization
1. **Initialize a New Node.js Project**
   ```bash
   mkdir project_name
   cd project_name
   npm init -y
   ```

---

## 🛠️ Install Core Dependencies
1. **Install Express** - Fast and lightweight web framework.
   ```bash
   npm install express
   ```

2. **Install Nodemon** - Automatically restarts the server during development.
   ```bash
   npm install --save-dev nodemon
   ```
   - Update `package.json` to include a start script:
     ```json
     "scripts": {
       "start": "node index.js",
       "dev": "nodemon index.js"
     }
     ```

3. **Install dotenv** - Manage environment variables.
   ```bash
   npm install dotenv
   ```

4. **Install CORS** - Enable Cross-Origin Resource Sharing.
   ```bash
   npm install cors
   ```

5. **Install Body Parser** - Parse incoming request bodies.
   ```bash
   npm install body-parser
   ```

---

## 🛠️ Install MongoDB Dependencies
1. **Install MongoDB Node.js Driver**
   ```bash
   npm install mongodb
   ```

2. **Install Mongoose** - A MongoDB object modeling tool.
   ```bash
   npm install mongoose
   ```

3. **Basic Mongoose Setup**
   ```js
   const mongoose = require('mongoose');

   mongoose.connect('mongodb://localhost:27017/your-database-name', {
     useNewUrlParser: true,
     useUnifiedTopology: true
   }).then(() => {
     console.log('Connected to MongoDB');
   }).catch((error) => {
     console.error('Error connecting to MongoDB:', error);
   });
   ```

---

## 🛠️ Authentication Dependencies
1. **Install JSON Web Token (JWT)** - For secure authentication.
   ```bash
   npm install jsonwebtoken
   ```

2. **Install bcrypt** - For password hashing.
   ```bash
   npm install bcrypt
   ```

---

## 🛠️ Logging and Debugging
1. **Install Morgan** - HTTP request logger.
   ```bash
   npm install morgan
   ```

2. **Install Debug** - Debugging utility.
   ```bash
   npm install debug
   ```

---

## 🛠️ Testing Tools
1. **Install Jest** - JavaScript testing framework.
   ```bash
   npm install --save-dev jest
   ```

2. **Install Supertest** - HTTP assertions for integration testing.
   ```bash
   npm install --save-dev supertest
   ```

---

## 🛠️ Additional Utilities
1. **Install Multer** - File upload handling.
   ```bash
   npm install multer
   ```

2. **Install Compression** - Gzip compression for responses.
   ```bash
   npm install compression
   ```

3. **Install Helmet** - Security middleware.
   ```bash
   npm install helmet
   ```

4. **Install EJS** - Template engine for dynamic HTML.
   ```bash
   npm install ejs
   ```

---

## 🌟 Running the Project
1. Start the server in development mode:
   ```bash
   npm run dev
   ```

2. Start the server in production mode:
   ```bash
   npm run start
   ```

---

## 🌟 These steps ensure your backend server is equipped with essential tools for building, testing, and securing APIs. Choose dependencies as per your project requirements!
