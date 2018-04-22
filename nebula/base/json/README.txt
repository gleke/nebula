## json序列化/反序列化库
> 参考Kapok实现

### Kapok:
- 更好的序列化库，纯c++14开发，header-only，简洁高效。
- Kapok---一个更好的序列化/反序列化库
- 可以很方便的将对象序列化和反序列化，序列化后的格式是标准的json格式。
- wiki介绍：https://github.com/qicosmos/Kapok/wiki 社区：http://purecpp.org/
- https://github.com/qicosmos/Kapok

### nebula的实现
  nebula是基于folly的，而folly已经自带了json库，基于dynamic实现，而Kapok是基于rapidjson的，nebula的实现里，移除了rapidjson的相关代码，使用dynamic。

### 感谢qicosmos，感谢Kapok


