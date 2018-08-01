import cyaron as cy


def gerenateData(_n):
    for i in range(0,len(_n)):
        data_output = cy.IO(file_prefix="data",data_id=i+1,disable_output=False)
        data_output.input_writeln(_n[i])
        data_output.input_write(cy.Vector.random(_n[i],[(1,1000)]))
        data_output.output_gen("mergeSort.exe") # 待测试的排序程序



