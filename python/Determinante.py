def determinante(matrix, size ,fil = 0, col = set()):
        if size < 2:
                if size == 1:
                        if len(matrix) != 1:
                                element = (set(range(fil + 1)) - col).pop()
                                return matrix[fil][element]
                        else:
                                return matrix[0]
                elif size == 0:
                        return 0
        else:
                res, par = 0, True
                for i in set(range(len(matrix))) - col:
                                adj = (-1) ** (par := not par) * matrix[fil][i]
                                if adj != 0:
                                        res += determinante(matrix, size - 1, fil + 1, col | set([i])) * adj
                return res
print(determinante(matrix = [
        [1,2,3,3,98,0,1,3,5,5],
        [4,5,6,-1,0,0,0,0,2,3],
        [7,8,9,5,0,-1,0,0,1,1],
        [3.5,2,0,0,0,1,0,0,1,1],
        [2,3,8,-0.5,2,1,0,0,1,1],
        [0,0,0,0,0,3,0,0,0,0],
        [1,0,0,0,0,0,0,0,98,79],
        [0,1,0,0,1,0,1,0,-1,-1],
        [0,0,0,0,0,0,0,0,0,1],
        [0,0,0,0,0,0,0,0,0,1]
        ], size = 10))
print(determinante(matrix=[], size = 0))
print(determinante(matrix=[99],size = 1))
print(determinante(matrix=[[1,2],[99,12]],size = 2))