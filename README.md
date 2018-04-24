# nebula
基于folly、wangle和proxygen的c++14基础库

## build
###

```cpp
// 进入nebula目录
mkdir out
cd out
cmake .. -DCATCH_INCLUDE_DIR=.. -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib
```

