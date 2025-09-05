## ✅ ১. Runtime Dependencies (server এ লাগবে)

```bash
npm install express cors dotenv mongoose morgan http-status
```

* **express** → মূল সার্ভার ফ্রেমওয়ার্ক
* **cors** → cross-origin requests handle করার জন্য
* **dotenv** → `.env` থেকে config load করার জন্য
* **mongoose** → MongoDB ORM
* **morgan** → লগার (request logs)
* **http-status** → HTTP status codes (২০০, ৪০৪ ইত্যাদি readable ভাবে ব্যবহার করতে)

---

## ✅ ২. Dev Dependencies (শুধু development এর জন্য)

```bash
npm install -D typescript ts-node-dev
npm install -D @types/node @types/express @types/cors @types/morgan
```

* **typescript** → TypeScript support
* **ts-node-dev** → dev server auto restart (nodemon এর মতো, কিন্তু TS friendly)
* **@types/...** → TypeScript type definitions

---

## ✅ ৩. Optional (error handling, validation ইত্যাদি)

```bash
npm install joi bcrypt jsonwebtoken
npm install -D @types/jsonwebtoken
```

* **joi** → schema validation
* **bcrypt** → password hashing
* **jsonwebtoken** → JWT auth

---

## ✅ ৪. `tsconfig.json` সেটআপ (TypeScript config)

প্রজেক্ট root এ একটা `tsconfig.json` ফাইল বানাও:

```json
{
  "compilerOptions": {
    "target": "ES2020",
    "module": "ESNext",
    "moduleResolution": "Node",
    "esModuleInterop": true,
    "forceConsistentCasingInFileNames": true,
    "strict": true,
    "skipLibCheck": true,
    "outDir": "dist",
    "baseUrl": "./src",
    "resolveJsonModule": true
  },
  "include": ["src"],
  "exclude": ["node_modules", "dist"]
}
```

---

## ✅ ৫. package.json scripts

```json
"scripts": {
  "dev": "ts-node-dev --respawn --transpile-only src/server.ts",
  "build": "tsc",
  "start": "node dist/server.js"
}
```

---

👉 এভাবে তোমার সার্ভার হবে:

* **Dev mode:** `npm run dev` → hot reload সহ
* **Prod mode:**

  ```bash
  npm run build
  npm start
  ```

---
