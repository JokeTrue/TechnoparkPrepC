if __name__ == '__main__':
    f = open('../DZ#2/file1.txt', 'wr+')
    rows = 15
    cols = 15
    f.write('{}\n'.format(rows))
    f.write('{}\n'.format(cols))
    f.write('{}\n'.format(rows*cols))

    n = 0
    for i in range(rows):
        for j in range(cols):
            f.write("{} {} {}\n".format(i, j, n))
            n += 1
    f.close()
