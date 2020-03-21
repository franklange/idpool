# idpool

Tiny id generator.  

The pool will always hand out the next smallest available id.  
Generated ids can be released back into the pool and will be handed out first on next pull.  

Thread-safe version also available.

```c++
idpool_t pool;

print(pool.next()) // 0
print(pool.next()) // 1
print(pool.next()) // 2

pool.release(1)

print(pool.next()) // 1
print(pool.next()) // 3
```
