// add modern include guards

#include <vector>

class AutoAnnotator {
private:
    std::vector<int> mQueues;
    int mDimension;
    int mLength;
    std::vector<int> mBestDistribution;
    int mBestWaste;
    
    int calculateWaste(const std::vector<int>& distribution);
    void calculateOptimum(std::vector<int>& workQueue, std::vector<int>& distribution, int taskId);
    std::vector<int> formatDistribution(std::vector<int> distribution);
    bool tryAssignTaskToNode(std::vector<int>& workQueue, int taskId, int nodeId);
    void removeAssignedTaskFromNode(std::vector<int>& workQueue, int taskId, int nodeId);
    void checkAndSaveDistribution(const std::vector<int>& distribution);
public:
    AutoAnnotator(const std::vector<int>& queues, int dimension)
    : mQueues(queues), mDimension(dimension), mLength(queues.size() / 2 / dimension) {
        mBestDistribution = std::vector<int>(mLength, mLength);
        mBestWaste = calculateWaste(mBestDistribution);
    }
    /**
        Calculates one optimal solution.
    */
    std::vector<int> annotate();
    /**
        Pretty prints the stored best distribution.
    */
    void printDistribution();
};