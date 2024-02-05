default:
	make -r pro

pro:
	gcc -o3 -o2 main.cpp -o A-small-program.exe
	pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pyinstaller
	pyinstaller -F calc.py
