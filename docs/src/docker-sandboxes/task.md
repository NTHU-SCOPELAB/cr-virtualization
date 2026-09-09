### 1. Download test files
```bash
git clone https://github.com/TsaiPeiChen1022/MNIST-with-CNN.git
```
### 2. Start the sandbox(run as administrator)
```bash
sbx run shell <path to MNIST-with-CNN dir>
```
### 3. Measure training execution time
 
```bash
sudo apt install python3-h5py
sudo apt install python3-numpy
python3 CNN.py
```
The output should look like this below success:
![](../../assets/2026-09-09-171406.png)
### 4. Also perform steps 1 and 3 in the VM.
You can either use one of the guest VMs from the live migration or set up a separate VM.