# Assignment

## Requirements
### 1. Demo (40 points)
- You need to demonstrate the above steps of the presentation through a screen recording, showing how you perform live migration on VMs using the framework we provided. 
- (only the live migration part is required, including the process of setting up 2 guests, but not the installation process)
- Naming the record video file as `HW1_<your_student_id>.xxx`, e.g. `HW1_113062566.mov` or `HW1_113062566.mp4`.
- The length of this video should not exceed ***30 minutes***.
- Upload the video to a cloud storage service and provide a link ***with viewing permission***.
    - This can be done using YouTube, Google Drive, Dropbox, or any other similar service.
- Example:
<iframe width="560" height="315" src="https://www.youtube.com/embed/0_64k7rplVk?si=ran08XJwlBHGmlFf" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

### 2. Report (60 points)
- You have to make a report of ***pdf format*** named `HW1_<your_student_id>.pdf`, e.g. `HW1_113062566.pdf`.
- The report should include the following items:
    - A. Provide a detailed explanation of each instruction, including the purpose of individual arguments within the commands. **(5 points)**
    - B. Show the performance testing results by `perf` with and without `-enable-kvm` on VM; furthermore compare among them and simply explain the results **(10 points)**
    - C. Show the performance testing results by `iperf` with and without `virtio` on VM; furthermore compare among them and explain the results **(10 points)**
    - D. Show the performance measurements by `perf` and `iperf` during the live migration is progressing; furthermore, simply describe your observations. **(10 points)**
    - E. What is "live migration" and why we need it. **(10 points)**
    - F. QEMU has a "fault tolerance" feature called [COLO](https://wiki.qemu.org/Features/COLO). We don’t ask you to utilize this feature in this assignment, but some questions you may answer :
        - What is fault-tolerance in virtualization technology and why we require it? **(7.5 points)**
        - What are the relationships between live migration and fault-tolerance? **(7.5 points)**

## Submission
Submit both the demo video link and the report to eeclass.


## Deadline
The deadline is set for October 25, 2024. Late submission is not allowed. 


If you have any question, feel free to asking through eeclass or email.
