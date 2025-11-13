# Helper: Using K8sGPT to help debugging your issue

## THIS PART IS NOT A REQUIREMENT, YOU WON'T EARN ANY EXTRA POINTS BY PUTTING THIS INTO YOUR REPORT.

## 0. Prerequisite
- You need to have a google account that have access to Google AI Studio.
- You can use your local or other model provider as [backend](https://docs.k8sgpt.ai/reference/providers/backend/), but we'll use the free `gemini-2.5-flash` API from Google AI Studio as an example here.
- If you care about privacy when running K8sGPT on your PC, you may want to [check this out](https://docs.k8sgpt.ai/reference/guidelines/privacy/).


## 1. Install K8sGPT
- Follow the official instructions [here](https://docs.k8sgpt.ai/getting-started/installation/).
- Or download the binaries directly from the [latest release](https://github.com/k8sgpt-ai/k8sgpt/releases/tag/latest).


## 2. Generate API Key from Google AI Studio
### a. Go to [Google AI Studio](https://studio.google.com/) and sign in with your Google account.

### b. Click on "Get API Key" button on the bottom left corner.
<img width="865" height="552" alt="image" src="https://github.com/user-attachments/assets/952895d6-31d6-4222-b951-a972f55dda0b" />


### c. Create API Key
<img width="866" height="552" alt="image" src="https://github.com/user-attachments/assets/62558e2e-e5fb-42e6-9311-cb388eabfd8e" />
<img width="780" height="493" alt="image" src="https://github.com/user-attachments/assets/67d79e09-8462-4984-a0ba-ca0b06456b67" />
<img width="847" height="534" alt="image" src="https://github.com/user-attachments/assets/21ad748c-e6b1-45fe-9854-41be4bb09fbf" />
<img width="775" height="442" alt="image" src="https://github.com/user-attachments/assets/154b3340-f3eb-4ac1-af27-a60c8f30f1bb" />


### d. Copy the generated API key and save it somewhere safe.
<img width="864" height="552" alt="image" src="https://github.com/user-attachments/assets/8b2c8139-2388-474f-a189-7c1301993dec" />


## 3. Setup K8sGPT to use Gemini API as backend
- Replace `YOUR_API_KEY` with the API key you generated in step 2.
```bash
k8sgpt auth add --backend google --model gemini-2.5-flash --password "YOUR_API_KEY"
```
<img width="1460" alt="image" src="https://github.com/user-attachments/assets/d31cc34f-3111-4fca-89cf-bca16ba60515" />

## 4. Ask K8sGPT to analyze your cluster and try to explain the issue:
```bash
k8sgpt analyze --explain --backend google
```
- Result:
```
➜  k8s git:(main) ✗ k8sgpt analyze --explain --backend google                                                             
W1012 01:04:58.380993 3501705 warnings.go:70] v1 Endpoints is deprecated in v1.33+; use discovery.k8s.io/v1 EndpointSlice
100% |████████████████████████████████████████████████████████████████████████████████████| (13/13, 8 it/min)
AI Provider: google

0: Deployment default/socket-server()
- Error: Deployment default/socket-server has 1 replicas in spec but 2 replicas in status because status field is not updated yet after scaling and 0 replicas are available with status running
Error: Deployment spec (1) and status (2) mismatch, likely due to a delayed status update after scaling. No pods are currently running.
Solution: 1. Wait a moment; it often self-corrects. 2. If persistent, check `kubectl get pods -l app=socket-server` for pod status. 3. If pods are stuck, `kubectl describe pod <pod-name>` for events/errors.

1: ConfigMap default/kube-root-ca.crt()
- Error: ConfigMap kube-root-ca.crt is not used by any pods in the namespace
Error: ConfigMap 'kube-root-ca.crt' exists but no pods in this namespace are configured to use it. It's currently unused.
Solution: 1. If required, modify pod spec to mount it. 2. If not, delete it: `kubectl delete cm kube-root-ca.crt`.

2: ConfigMap kube-node-lease/kube-root-ca.crt()
- Error: ConfigMap kube-root-ca.crt is not used by any pods in the namespace
Error: ConfigMap 'kube-root-ca.crt' exists but no pods in this namespace are configured to use it. It's currently unused.
Solution: 1. If required, modify pod spec to mount it. 2. If not, delete it: `kubectl delete cm kube-root-ca.crt`.

3: ConfigMap kube-public/cluster-info()
- Error: ConfigMap cluster-info is not used by any pods in the namespace
Error: ConfigMap 'cluster-info' exists but no pods are currently configured to use it in the namespace.
Solution: 1. Verify if 'cluster-info' is still required. 2. If not, delete it: `kubectl delete configmap cluster-info`.

4: ConfigMap kube-public/kube-root-ca.crt()
- Error: ConfigMap kube-root-ca.crt is not used by any pods in the namespace
Error: ConfigMap 'kube-root-ca.crt' exists but no pods in this namespace are configured to use it. It's currently unused.
Solution: 1. If required, modify pod spec to mount it. 2. If not, delete it: `kubectl delete cm kube-root-ca.crt`.

5: ConfigMap kube-system/extension-apiserver-authentication()
- Error: ConfigMap extension-apiserver-authentication is not used by any pods in the namespace
Error: ConfigMap 'extension-apiserver-authentication' exists but no pods in the namespace are configured to use it.
Solution: 1. Confirm if this ConfigMap is truly needed. 2. If not, delete it: `kubectl delete cm extension-apiserver-authentication`.

6: ConfigMap kube-system/kube-apiserver-legacy-service-account-token-tracking()
- Error: ConfigMap kube-apiserver-legacy-service-account-token-tracking is not used by any pods in the namespace
Error: ConfigMap `kube-apiserver-legacy-service-account-token-tracking` exists but no pods use it. It's likely obsolete or misconfigured.
Solution:
1. Verify if ConfigMap is needed.
2. If not, delete it: `kubectl delete cm kube-apiserver-legacy-service-account-token-tracking -n <ns>`.
3. If needed, check pod specs.

7: ConfigMap kube-system/kube-root-ca.crt()
- Error: ConfigMap kube-root-ca.crt is not used by any pods in the namespace
Error: ConfigMap 'kube-root-ca.crt' exists but no pods in this namespace are configured to use it. It's currently unused.
Solution: 1. If required, modify pod spec to mount it. 2. If not, delete it: `kubectl delete cm kube-root-ca.crt`.

8: ConfigMap kube-system/kubeadm-config()
- Error: ConfigMap kubeadm-config is not used by any pods in the namespace
Error: The `kubeadm-config` ConfigMap exists but no pods are currently using it.
Solution: 1. Verify if it's still needed. 2. If not, delete it: `kubectl delete cm kubeadm-config -n kube-system`.

9: ConfigMap kube-system/kubelet-config()
- Error: ConfigMap kubelet-config is not used by any pods in the namespace
Error: The ConfigMap named 'kubelet-config' exists in the namespace but no running pods are currently configured to mount or reference it, making it an unused resource.
Solution: 1. Verify if 'kubelet-config' is still required. 2. If not, delete it: `kubectl delete cm kubelet-config`. 3. If needed, update relevant pod specs to mount it.

10: Service default/socket-server-service()
- Error: Service has not ready endpoints, pods: [Pod/socket-server-76b4f57897-7vtjl Pod/socket-server-7fdb5cb468-drlg6], expected 2
Error: The Service can't route traffic because its pods aren't ready or healthy.
Solution: 1. `kubectl get pods` for status. 2. `kubectl logs <pod-name>` for errors. 3. `kubectl describe pod <pod-name>` for events/readiness. 4. Verify container port matches Service targetPort.

11: Pod default/socket-server-76b4f57897-7vtjl(Deployment/socket-server)
- Error: Failed to apply default image tag "server-<your student ID>": couldn't parse image name "server-<your student ID>": invalid reference format: repository name (library/server-<your student ID>) must be lowercase
Error: Image repository names must be lowercase. Your image name `server-<ID>` contains uppercase characters, causing an invalid reference format.
Solution: 1. Change the image name `server-<ID>` to all lowercase (e.g., `server-<id>`).
2. Update your Kubernetes manifest (YAML) with the corrected image name.

12: Pod default/socket-server-7fdb5cb468-drlg6(Deployment/socket-server)
- Error: Container image "server-113062566" is not present with pull policy of Never
Error: Container image "server-113062566" isn't found on the node; its 'Never' pull policy prevents downloading.
Solution: 1. Ensure image is built/loaded onto the node. 2. Or, update pod spec's `imagePullPolicy` to `IfNotPresent` to allow pulling from a registry.
```

- Now you can start to look for hints to solve the issue, or feed this information to the LLM you use to provide better context to solve your problem.
```bash
# Before proceeding, make sure you have modified the deployment.yaml accordingly(socket-server container name).
# In docker/server, build the image inside minikube
minikube image build -t server-<your student ID> .

# In k8s, after patching the image name in deployment.yaml
kubectl delete -f service.yaml
kubectl delete -f deployment.yaml
kubectl apply -f deployment.yaml
kubectl apply -f service.yaml

# Check if everything is working now
kubectl get all
```
<img width="1323" alt="image" src="https://github.com/user-attachments/assets/4d71c69a-b586-492a-b454-09c53909b9a2" />

