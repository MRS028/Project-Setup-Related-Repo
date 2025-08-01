
### 🔹 Step A: Create a New React App

```bash
npx create-react-app my-redux-app
cd my-redux-app
```

---

### 🔹 Step B: Install Redux Toolkit and React-Redux

```bash
npm install @reduxjs/toolkit react-redux
```

> ✅ `@reduxjs/toolkit` is the official, recommended way to write Redux logic.
> ✅ `react-redux` connects Redux with React components.

---

### 🔹 Step C: Create the Redux Store

📁 Create a folder called `app` inside `src`:

```bash
mkdir src/app
```

📄 `src/app/store.js`:

```js
import { configureStore } from '@reduxjs/toolkit';
import counterReducer from '../features/counter/counterSlice';

export const store = configureStore({
  reducer: {
    counter: counterReducer,
  },
});
```

---

### 🔹 Step D: Create a Redux Slice

📁 Create a `features/counter` folder:

```bash
mkdir -p src/features/counter
```

📄 `src/features/counter/counterSlice.js`:

```js
import { createSlice } from '@reduxjs/toolkit';

const initialState = {
  value: 0,
};

const counterSlice = createSlice({
  name: 'counter',
  initialState,
  reducers: {
    increment: (state) => {
      state.value += 1;
    },
    decrement: (state) => {
      state.value -= 1;
    },
    incrementByAmount: (state, action) => {
      state.value += action.payload;
    },
  },
});

export const { increment, decrement, incrementByAmount } = counterSlice.actions;
export default counterSlice.reducer;
```

---

### 🔹 Step E: Provide the Redux Store to React

📄 `src/index.js`:

```js
import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import { store } from './app/store';
import { Provider } from 'react-redux';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>
);
```

---

### 🔹 Step F: Use Redux in a Component

📄 `src/App.js`:

```js
import React from 'react';
import { useSelector, useDispatch } from 'react-redux';
import { increment, decrement, incrementByAmount } from './features/counter/counterSlice';

function App() {
  const count = useSelector((state) => state.counter.value);
  const dispatch = useDispatch();

  return (
    <div style={{ padding: '2rem' }}>
      <h1>Redux Counter</h1>
      <h2>{count}</h2>
      <button onClick={() => dispatch(increment())}>+1</button>
      <button onClick={() => dispatch(decrement())}>-1</button>
      <button onClick={() => dispatch(incrementByAmount(5))}>+5</button>
    </div>
  );
}

export default App;
```


---

## 🔥 ADVANCED REDUX CONCEPTS & ADD-ONS

---

### 1. ✅ **Using `createAsyncThunk` for Async Logic (API Calls)**

Instead of writing manual `dispatch`es for async actions, use `createAsyncThunk`.

📄 `features/posts/postsSlice.js`

```js
import { createSlice, createAsyncThunk } from '@reduxjs/toolkit';
import axios from 'axios';

export const fetchPosts = createAsyncThunk('posts/fetchPosts', async () => {
  const response = await axios.get('https://jsonplaceholder.typicode.com/posts');
  return response.data;
});

const postsSlice = createSlice({
  name: 'posts',
  initialState: { items: [], status: 'idle' },
  reducers: {},
  extraReducers: (builder) => {
    builder
      .addCase(fetchPosts.pending, (state) => {
        state.status = 'loading';
      })
      .addCase(fetchPosts.fulfilled, (state, action) => {
        state.status = 'succeeded';
        state.items = action.payload;
      })
      .addCase(fetchPosts.rejected, (state) => {
        state.status = 'failed';
      });
  },
});

export default postsSlice.reducer;
```

🔁 Add `posts` reducer to your `store.js`.

---

### 2. 🧱 **Redux Slice Code Splitting (Modular Architecture)**

Instead of a giant reducer file, split logic into **feature-based folders**:

```
src/
├── app/
│   └── store.js
├── features/
│   ├── counter/
│   │   └── counterSlice.js
│   └── posts/
│       └── postsSlice.js
```

---

### 3. 🧪 **Redux DevTools Integration (built-in with Toolkit)**

Redux Toolkit auto-configures Redux DevTools extension, so you're already using it if your browser supports it.

---

### 4. 🔒 **Middleware (e.g. Logger, Auth)**

```js
import logger from 'redux-logger';

export const store = configureStore({
  reducer: {
    counter: counterReducer,
  },
  middleware: (getDefaultMiddleware) =>
    getDefaultMiddleware().concat(logger),
});
```

---

### 5. 🧪 **Testing Redux Slices**

Using Jest:

```js
import counterReducer, { increment } from './counterSlice';

test('should handle initial state', () => {
  expect(counterReducer(undefined, { type: 'unknown' })).toEqual({ value: 0 });
});

test('should handle increment', () => {
  const actual = counterReducer({ value: 3 }, increment());
  expect(actual.value).toEqual(4);
});
```

---

### 6. 🌐 **Persist Redux State (Redux-Persist)**

To store Redux state in `localStorage`:

```bash
npm install redux-persist
```

📄 Update `store.js`:

```js
import { configureStore } from '@reduxjs/toolkit';
import counterReducer from '../features/counter/counterSlice';
import { persistStore, persistReducer } from 'redux-persist';
import storage from 'redux-persist/lib/storage';
import { combineReducers } from 'redux';

const persistConfig = {
  key: 'root',
  storage,
};

const rootReducer = combineReducers({
  counter: counterReducer,
});

const persistedReducer = persistReducer(persistConfig, rootReducer);

export const store = configureStore({
  reducer: persistedReducer,
});

export const persistor = persistStore(store);
```

📄 Wrap in `PersistGate` in `index.js`:

```js
import { PersistGate } from 'redux-persist/integration/react';
import { persistor } from './app/store';

<Provider store={store}>
  <PersistGate loading={null} persistor={persistor}>
    <App />
  </PersistGate>
</Provider>
```

---

### 7. 💬 **RTK Query (Data Fetching Library with Redux)**

RTK Query is built into Redux Toolkit and simplifies API integration.

```bash
npm install @reduxjs/toolkit
```

📄 Create API slice:

```js
// src/features/api/apiSlice.js
import { createApi, fetchBaseQuery } from '@reduxjs/toolkit/query/react';

export const apiSlice = createApi({
  reducerPath: 'api',
  baseQuery: fetchBaseQuery({ baseUrl: 'https://jsonplaceholder.typicode.com' }),
  endpoints: (builder) => ({
    getPosts: builder.query({
      query: () => '/posts',
    }),
  }),
});

export const { useGetPostsQuery } = apiSlice;
```

📄 Update `store.js`:

```js
import { apiSlice } from '../features/api/apiSlice';

export const store = configureStore({
  reducer: {
    [apiSlice.reducerPath]: apiSlice.reducer,
  },
  middleware: (getDefaultMiddleware) =>
    getDefaultMiddleware().concat(apiSlice.middleware),
});
```

📄 Use in component:

```js
import { useGetPostsQuery } from './features/api/apiSlice';

function App() {
  const { data: posts, isLoading } = useGetPostsQuery();

  return (
    <div>
      {isLoading ? 'Loading...' : posts.map((p) => <div key={p.id}>{p.title}</div>)}
    </div>
  );
}
```

---

## ✅ BONUS: Production Setup Tips

* Use `redux-logger` only in development.
* Use selectors to abstract state access.
* Use `immer` (built into Redux Toolkit) to simplify immutable logic.
* Normalize complex state using `createEntityAdapter`.

---

## 🟦 REDUX + TYPESCRIPT Setup (Step-by-Step)

Let’s build a fully typed Redux app using **Redux Toolkit (RTK)** + **React-Redux** + **TypeScript**.

---

### 📦 1. Create a TypeScript React App

```bash
npx create-react-app my-redux-ts-app --template typescript
cd my-redux-ts-app
```

---

### 📥 2. Install Redux Toolkit and React-Redux

```bash
npm install @reduxjs/toolkit react-redux
```

---

### 🏗️ 3. Setup Redux Store

📁 `src/app/store.ts`:

```ts
import { configureStore } from '@reduxjs/toolkit';
import counterReducer from '../features/counter/counterSlice';

export const store = configureStore({
  reducer: {
    counter: counterReducer,
  },
});

// Export types for RootState and AppDispatch
export type RootState = ReturnType<typeof store.getState>;
export type AppDispatch = typeof store.dispatch;
```

---

### 🧠 4. Setup Typed Hooks (Optional but Recommended)

📄 `src/app/hooks.ts`:

```ts
import { TypedUseSelectorHook, useDispatch, useSelector } from 'react-redux';
import type { RootState, AppDispatch } from './store';

export const useAppDispatch = () => useDispatch<AppDispatch>();
export const useAppSelector: TypedUseSelectorHook<RootState> = useSelector;
```

---

### 📦 5. Create a Typed Redux Slice

📁 `src/features/counter/counterSlice.ts`:

```ts
import { createSlice, PayloadAction } from '@reduxjs/toolkit';

interface CounterState {
  value: number;
}

const initialState: CounterState = {
  value: 0,
};

const counterSlice = createSlice({
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

---

### 🧩 6. Provide the Redux Store

📄 `src/index.tsx`:

```tsx
import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import { Provider } from 'react-redux';
import { store } from './app/store';

const root = ReactDOM.createRoot(document.getElementById('root')!);
root.render(
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>
);
```

---

### 🧪 7. Use Redux in a Component

📄 `src/App.tsx`:

```tsx
import React from 'react';
import { useAppDispatch, useAppSelector } from './app/hooks';
import { increment, decrement, incrementByAmount } from './features/counter/counterSlice';

function App() {
  const count = useAppSelector((state) => state.counter.value);
  const dispatch = useAppDispatch();

  return (
    <div style={{ padding: '2rem' }}>
      <h1>Redux Toolkit + TypeScript</h1>
      <h2>{count}</h2>
      <button onClick={() => dispatch(increment())}>+1</button>
      <button onClick={() => dispatch(decrement())}>-1</button>
      <button onClick={() => dispatch(incrementByAmount(5))}>+5</button>
    </div>
  );
}

export default App;
```

---

## ✅ Bonus: `createAsyncThunk` with TypeScript

📄 `src/features/posts/postsSlice.ts`:

```ts
import { createAsyncThunk, createSlice } from '@reduxjs/toolkit';
import axios from 'axios';

interface Post {
  id: number;
  title: string;
}

interface PostsState {
  items: Post[];
  status: 'idle' | 'loading' | 'succeeded' | 'failed';
}

const initialState: PostsState = {
  items: [],
  status: 'idle',
};

export const fetchPosts = createAsyncThunk<Post[]>('posts/fetchPosts', async () => {
  const res = await axios.get<Post[]>('https://jsonplaceholder.typicode.com/posts');
  return res.data;
});

const postsSlice = createSlice({
  name: 'posts',
  initialState,
  reducers: {},
  extraReducers(builder) {
    builder
      .addCase(fetchPosts.pending, (state) => {
        state.status = 'loading';
      })
      .addCase(fetchPosts.fulfilled, (state, action) => {
        state.status = 'succeeded';
        state.items = action.payload;
      })
      .addCase(fetchPosts.rejected, (state) => {
        state.status = 'failed';
      });
  },
});

export default postsSlice.reducer;
```

---

## 🎯 What You Get

✅ Strongly typed `store`, `slice`, and `hooks`
✅ Safer `useSelector`, `useDispatch`
✅ Autocomplete everywhere
✅ Optional async support via `createAsyncThunk`

---


