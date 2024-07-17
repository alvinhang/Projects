def max_temp(data : list[float]) -> float:
    temp = data[0]
    for t in data:
        if t > temp:
            temp = t
    print(temp)
    return temp