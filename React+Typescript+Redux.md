Here's a complete guide to set up your React project with TypeScript, Redux, Tailwind, Shadcn, and DaisyUI using Vite for the `npm run dev` experience:

### 1. Create Project with Vite + TypeScript
```bash
npm create vite@latest my-app -- --template react-ts
cd my-app
```

### 2. Install Dependencies
```bash
# Core dependencies
npm install @reduxjs/toolkit react-redux

# Tailwind + DaisyUI
npm install -D tailwindcss postcss autoprefixer daisyui
npx tailwindcss init -p

# Shadcn UI
npm install -g shadcn-ui
npx shadcn-ui@latest init

# Additional dev dependencies
npm install -D @types/node @types/react @types/react-dom
```

### 3. Configure Tailwind CSS
**`tailwind.config.js`:**
```javascript
/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {},
  },
  plugins: [
    require("daisyui"),
  ],
  daisyui: {
    themes: ["light", "dark"],
  },
}
```

**`src/index.css`:**
```css
@tailwind base;
@tailwind components;
@tailwind utilities;
```

### 4. Configure Shadcn UI
During initialization (`npx shadcn-ui@latest init`), select:
- Style: `Default`
- Base color: `Slate`
- CSS variables: `Yes`
- Tailwind config location: `tailwind.config.js`
- Components location: `src/components/ui`

### 5. Setup Redux Store
**`src/app/store.ts`:**
```typescript
import { configureStore } from '@reduxjs/toolkit';
import counterReducer from '../features/counter/counterSlice';

export const store = configureStore({
  reducer: {
    counter: counterReducer,
  },
});

export type RootState = ReturnType<typeof store.getState>;
export type AppDispatch = typeof store.dispatch;
```

**`src/features/counter/counterSlice.ts`:**
```typescript
import { createSlice, PayloadAction } from '@reduxjs/toolkit';

interface CounterState {
  value: number;
}

const initialState: CounterState = {
  value: 0,
};

export const counterSlice = createSlice({
  name: 'counter',
  initialState,
  reducers: {
    increment: (state) => {
      state.value += 1;
    },
    decrement: (state) => {
      state.value -= 1;
    },
    incrementByAmount: (state, action: PayloadAction<number>) => {
      state.value += action.payload;
    },
  },
});

export const { increment, decrement, incrementByAmount } = counterSlice.actions;
export default counterSlice.reducer;
```

### 6. Configure Redux Provider
**`src/main.tsx`:**
```typescript
import React from 'react'
import ReactDOM from 'react-dom/client'
import { Provider } from 'react-redux'
import { store } from './app/store'
import App from './App.tsx'
import './index.css'

ReactDOM.createRoot(document.getElementById('root')!).render(
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>,
)
```

### 7. Create Redux Hooks
**`src/app/hooks.ts`:**
```typescript
import { useDispatch, useSelector } from 'react-redux';
import type { RootState, AppDispatch } from './store';

export const useAppDispatch = () => useDispatch<AppDispatch>();
export const useAppSelector: <T>(selector: (state: RootState) => T) => T = useSelector;
```

### 8. Example Component
**`src/App.tsx`:**
```typescript
import { useAppDispatch, useAppSelector } from './app/hooks';
import { decrement, increment } from './features/counter/counterSlice';
import { Button } from './components/ui/button';

function App() {
  const count = useAppSelector((state) => state.counter.value);
  const dispatch = useAppDispatch();

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-50 to-indigo-100 p-8">
      <div className="max-w-2xl mx-auto bg-white rounded-xl shadow-lg p-6">
        <h1 className="text-3xl font-bold text-center mb-8 text-gray-800">
          React + TypeScript + Redux + Tailwind + Shadcn + DaisyUI
        </h1>
        
        {/* Redux Counter */}
        <div className="flex flex-col items-center mb-8">
          <div className="text-4xl font-bold mb-4">{count}</div>
          <div className="flex gap-4">
            <Button 
              onClick={() => dispatch(increment())}
              className="bg-blue-500 hover:bg-blue-600"
            >
              Increment
            </Button>
            <Button 
              onClick={() => dispatch(decrement())}
              variant="outline"
            >
              Decrement
            </Button>
          </div>
        </div>

        {/* DaisyUI Components */}
        <div className="mb-8">
          <h2 className="text-xl font-semibold mb-4">DaisyUI Components</h2>
          <div className="flex flex-wrap gap-4">
            <button className="btn btn-primary">Primary</button>
            <button className="btn btn-secondary">Secondary</button>
            <button className="btn btn-accent">Accent</button>
            <div className="alert alert-info">
              <span>This is a DaisyUI alert!</span>
            </div>
          </div>
        </div>

        {/* Shadcn Components */}
        <div>
          <h2 className="text-xl font-semibold mb-4">Shadcn Components</h2>
          <div className="flex flex-wrap gap-4">
            <Button variant="default">Default</Button>
            <Button variant="destructive">Destructive</Button>
            <Button variant="outline">Outline</Button>
            <Button variant="secondary">Secondary</Button>
            <Button variant="ghost">Ghost</Button>
            <Button variant="link">Link</Button>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;
```

### 9. Add Shadcn Components
```bash
npx shadcn-ui@latest add button card input
```

### 10. Run the Application
```bash
npm run dev
```

### Key Configuration Notes:
1. **Vite Configuration**:
   - Uses Vite instead of Create React App for faster development
   - Default `npm run dev` starts on port 5173

2. **Redux Setup**:
   - Centralized store configuration
   - Type-safe state management with TypeScript
   - Custom hooks for cleaner component code

3. **UI Libraries**:
   - DaisyUI: Pre-styled components with built-in themes
   - Shadcn: Customizable components with CSS variables
   - Both work together but avoid mixing similar components

4. **Project Structure**:
```
src/
├── app/
│   ├── hooks.ts
│   └── store.ts
├── components/
│   └── ui/  # Shadcn components
├── features/
│   └── counter/
│       └── counterSlice.ts
├── App.tsx
├── main.tsx
└── index.css
```

### Additional Recommendations:
1. **Add Prettier**:
```bash
npm install -D prettier prettier-plugin-tailwindcss
```
Create `.prettierrc`:
```json
{
  "plugins": ["prettier-plugin-tailwindcss"],
  "tailwindConfig": "./tailwind.config.js"
}
```

2. **Add ESLint**:
```bash
npm install -D eslint @typescript-eslint/parser @typescript-eslint/eslint-plugin eslint-plugin-react
```

3. **Add Absolute Imports**:
**`tsconfig.json`**:
```json
{
  "compilerOptions": {
    "baseUrl": ".",
    "paths": {
      "@/*": ["./src/*"]
    }
  }
}
```

**`vite.config.ts`**:
```typescript
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import path from 'path'

export default defineConfig({
  plugins: [react()],
  resolve: {
    alias: {
      "@": path.resolve(__dirname, "./src"),
    },
  },
})
```

This setup gives you a modern React application with:
- Fast development server with Vite (`npm run dev`)
- Type safety with TypeScript
- Predictable state management with Redux Toolkit
- Utility-first styling with Tailwind CSS
- Component libraries with DaisyUI and Shadcn UI
- Professional development workflow with linting and formatting

You can now build your application using the best of both worlds: DaisyUI for rapid prototyping and Shadcn for customizable, accessible components, all while maintaining type safety and predictable state management.