# Automatic-testing
Graph Sort 
# Automatic-testing
Sort and Graph

在使用之前，确保当前Python环境里有 `` cyaron  `` ,如果没有可执行命令

```shell
pip install cyaron
```

##### 测试图的使用方法

```shell
python gerenate_graph.py
```

代码的第**13**行

```python
cy.Compare.program("Dijkstra.exe",input=data_output,std_program="SPFA.exe")
```

``std_program``表示标准的程序，`` Dijkstra.exe `` 为需要待测程序的可执行文件，程序会自动生成图来进行测试，默认生成3组测试样例。

没有出现错误，则程序正确。

##### 测试排序的使用方法



将待测试的可执行文件位置放在 `` gerenate_data1.py `` 的第**9**行方法的参数位置。

之后运行

```powershell
python randTest.py
```

将会随机对生成的数据进行测试，测试中，可修改`` gerenate_data1.py ``的第**25**行来修改随机测试次数。

如果有错误，将会输出第几组测试数据的那两个位置有错，如果没有错误，则输出 **All Correct!** 
