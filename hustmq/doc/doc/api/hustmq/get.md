`get`
----------

**接口:** `/hustmq/get`

**方法:** `GET`

**参数:** 

*  **queue** （必选）  
*  **worker** （必选）  

**使用范例:**

    curl -i -X GET "http://localhost:8085/hustmq/get?queue=test_queue&worker=s1.bjdt|9999"

**结果范例A1:**

	HTTP/1.1 412 Precondition Failed //queue not exist

**结果范例A2:**

	HTTP/1.1 404 Not Found //queue empty or locked

**结果范例A3:**

	HTTP/1.1 200 OK
	Content-Length: 9
	Content-Type: text/plain

	test_item

[上一级](../hustmq.md)

[根目录](../../index.md)