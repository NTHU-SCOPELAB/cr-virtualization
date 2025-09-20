# Exploring Virtual Machine Live Migration: Performance Analysis and Optimization

## Live Migration
Live Migration is a crucial feature in virtualization technology that allows the transfer of a running virtual machine (VM) from one physical host to another without interrupting the VM's operation or services.
![](../assets/2025-06-10-21-20-15.png)

## The architecture we want to simulate:
<img width="449" height="253" alt="image" src="https://github.com/user-attachments/assets/d4c4f8e9-0685-4556-b1df-8f2cc279c459" />

## Our Homework Architecture:
Since not everyone will have 2 PCs available to run QEMU on them, we provided an alternative option:   
<img width="486" height="281" alt="image" src="https://github.com/user-attachments/assets/06c62b41-4dfe-48c7-8183-b4e3e82b49b5" />

- Note: VirtualBox now has native Apple Silicon support on Apple hardware with M-Series chips, but we haven't yet tested the nested virtualization feature, so this homework may not work out on your hardware by default.
- If you still want to test that out, feel free to ask us through the discussion/email on eeclass.
- Or you can use the PC room in C.L.Liu(EECS) 3F, we already have VirtualBox installed in there.
