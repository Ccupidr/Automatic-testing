import cyaron as cy


n = [7,20,30]
m = [20,40,60]

for i in range(3):
    data_output = cy.IO(file_prefix="data",data_id=i+1,disable_output=False)
    data_output.input_writeln(n[i],m[i])
    graph = cy.Graph.graph(n[i],m[i],directed=False,weight_limit=(2,10)) #建立n个点m条边的边权范围在2.10的有向图
    data_output.input_write(graph)
    data_output.output_gen("Dijkstra.exe")
    cy.Compare.program("Dijkstra.exe",input=data_output,std_program="SPFA.exe")
   