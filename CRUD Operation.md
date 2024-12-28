# CRUD Operations and Advanced Functionalities

## Basic CRUD Operations

### 1. Fetching All Documents
```javascript
app.get('/items', async (req, res) => {
    const cursor = collection.find();
    const result = await cursor.toArray();
    res.send(result);
});
```

### 2. Fetching a Single Document by ID
```javascript
app.get('/items/:id', async (req, res) => {
    const id = req.params.id;
    const query = { _id: new ObjectId(id) };
    const result = await collection.findOne(query);
    res.send(result);
});
```

### 3. Fetching a Single Document by Email
```javascript
app.get('/users/email/:email', async (req, res) => {
    const email = req.params.email;
    const query = { email: email };
    const result = await collection.findOne(query);
    res.send(result);
});
```

### 4. Adding a New Document
```javascript
app.post('/items', async (req, res) => {
    const newItem = req.body;
    const result = await collection.insertOne(newItem);
    res.send(result);
});
```

### 5. Updating a Document by ID
```javascript
app.put('/items/:id', async (req, res) => {
    const id = req.params.id;
    const filter = { _id: new ObjectId(id) };
    const options = { upsert: true };
    const updatedDoc = { $set: req.body };
    const result = await collection.updateOne(filter, updatedDoc, options);
    res.send(result);
});
```

### 6. Deleting a Document by ID
```javascript
app.delete('/items/:id', async (req, res) => {
    const id = req.params.id;
    const query = { _id: new ObjectId(id) };
    const result = await collection.deleteOne(query);
    res.send(result);
});
```

## Advanced Operations

### 1. Sorting
- **Ascending Order:**
```javascript
app.get('/items/sort/asc/:field', async (req, res) => {
    const field = req.params.field;
    const cursor = collection.find().sort({ [field]: 1 });
    const result = await cursor.toArray();
    res.send(result);
});
```

- **Descending Order:**
```javascript
app.get('/items/sort/desc/:field', async (req, res) => {
    const field = req.params.field;
    const cursor = collection.find().sort({ [field]: -1 });
    const result = await cursor.toArray();
    res.send(result);
});
```

### 2. Searching
```javascript
app.get('/items/search/:field/:keyword', async (req, res) => {
    const { field, keyword } = req.params;
    const query = { [field]: { $regex: keyword, $options: 'i' } };
    const cursor = collection.find(query);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 3. Filtering
```javascript
app.get('/items/filter/:field/:value', async (req, res) => {
    const { field, value } = req.params;
    const query = { [field]: value };
    const cursor = collection.find(query);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 4. Pagination
```javascript
app.get('/items/page/:page/:limit', async (req, res) => {
    const page = parseInt(req.params.page);
    const limit = parseInt(req.params.limit);
    const skip = (page - 1) * limit;
    const cursor = collection.find().skip(skip).limit(limit);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 5. Counting Documents
```javascript
app.get('/items/count', async (req, res) => {
    const count = await collection.countDocuments();
    res.send({ count });
});
```

### 6. Grouping Documents
```javascript
app.get('/items/group/:field', async (req, res) => {
    const field = `$${req.params.field}`;
    const pipeline = [
        { $group: { _id: field, count: { $sum: 1 } } }
    ];
    const cursor = collection.aggregate(pipeline);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 7. Distinct Values
```javascript
app.get('/items/distinct/:field', async (req, res) => {
    const field = req.params.field;
    const result = await collection.distinct(field);
    res.send(result);
});
```

### 8. Incrementing a Numeric Field
```javascript
app.put('/items/increment/:id/:field/:value', async (req, res) => {
    const { id, field, value } = req.params;
    const filter = { _id: new ObjectId(id) };
    const update = { $inc: { [field]: parseInt(value) } };
    const result = await collection.updateOne(filter, update);
    res.send(result);
});
```

## Extended Functionality

### 1. Checking Document Existence
```javascript
app.get('/items/exists/:field/:value', async (req, res) => {
    const { field, value } = req.params;
    const query = { [field]: value };
    const result = await collection.findOne(query);
    res.send(result ? true : false);
});
```

### 2. Fetching First Matching Document
```javascript
app.get('/items/first/:field/:value', async (req, res) => {
    const { field, value } = req.params;
    const query = { [field]: value };
    const result = await collection.findOne(query);
    res.send(result);
});
```

### 3. Limiting Documents
```javascript
app.get('/items/limit/:limit', async (req, res) => {
    const limit = parseInt(req.params.limit);
    const cursor = collection.find().limit(limit);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 4. Skipping Documents
```javascript
app.get('/items/skip/:skip', async (req, res) => {
    const skip = parseInt(req.params.skip);
    const cursor = collection.find().skip(skip);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 5. Multi-Field Sorting
```javascript
app.get('/items/sort/multi', async (req, res) => {
    const sortFields = req.query.fields.split(',');
    const sort = {};
    sortFields.forEach(field => {
        const direction = field.startsWith('-') ? -1 : 1;
        sort[field.replace('-', '')] = direction;
    });
    const cursor = collection.find().sort(sort);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 6. Aggregation Pipeline
```javascript
app.get('/items/aggregate', async (req, res) => {
    const pipeline = [
        { $match: { status: 'active' } },
        { $group: { _id: '$category', total: { $sum: 1 } } },
        { $sort: { total: -1 } }
    ];
    const cursor = collection.aggregate(pipeline);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 7. Range Queries
```javascript
app.get('/items/range/:field/:min/:max', async (req, res) => {
    const { field, min, max } = req.params;
    const query = { [field]: { $gte: parseInt(min), $lte: parseInt(max) } };
    const cursor = collection.find(query);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 8. Summing Numeric Fields
```javascript
app.get('/items/sum/:field', async (req, res) => {
    const field = req.params.field;
    const pipeline = [
        { $group: { _id: null, total: { $sum: `$${field}` } } }
    ];
    const cursor = collection.aggregate(pipeline);
    const result = await cursor.toArray();
    res.send(result);
});
```

### 9. Bulk Updating Documents
```javascript
app.put('/items/update-many', async (req, res) => {
    const filter = req.body.filter;
    const updateDoc = { $set: req.body.update };
    const result = await collection.updateMany(filter, updateDoc);
    res.send(result);
});
```

### 10. Replacing a Document
```javascript
app.put('/items/replace/:id', async (req, res) => {
    const id = req.params.id;
    const filter = { _id: new ObjectId(id) };
    const newDoc = req.body;
    const result = await collection.replaceOne(filter, newDoc);
    res.send(result);
});
