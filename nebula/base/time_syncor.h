/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NEBULA_BASE_TIME_SYNCORE_H_
#define NEBULA_BASE_TIME_SYNCORE_H_

#include <stdint.h>
#include <vector>
#include <algorithm>

/*
	TimeSyncor time_syncor;
	⋯
	if (TimeSyncor:: kMaxTimSamples == time_syncor.OnRecvTimeSample(sent_time, current_time)) {
	  最终同步的时钟= 当前时钟+time_syncor.GetCorrectedDelta();
	}
 */
// 时间同步器
class TimeSyncor {
public:
	static const size_t kMaxTimSamples = 10;

	TimeSyncor() {
		first_delta_flag_ = false;
	}

	// sent_time: 客户端发送给服务器的时间
	// current_time: 服务器返回给客户端的时间
	// return: 返回值为共循环了多少次
	size_t OnRecvTimeSample(uint64_t sent_time, uint64_t current_time) {
		
		int delta = (current_time-sent_time) / 2;
		if (!first_delta_flag_) {
			first_delta_flag_ = true;
			// 设置系统时间或记录数据
			// delta_time_
			return 0;
		} else {
			deltas_.push_back(delta);
			return deltas_.size();
		}
	}

	// 最终算出的平均值
	uint64_t GetCorrectedDelta() {
		// DCHECK(deltas_.size() > 2);

		// 排序
		std::sort(deltas_.begin(), deltas_.end());

		// 取中值
		int median = deltas_[deltas_.size()/2];

		int sum = 0;
		int count = 0;
		for (size_t i=0; i<deltas_.size(); ++i) {
			// 抛弃大于中值1.5倍的数值
			if (deltas_[i] < 1.5*median) {
				sum += deltas_[i];
				count++;
			}
		}

		// 使用算术平均得到一个平均值
		return sum / count;
	}


private:
	// 基准时间
	uint64_t delta_time_;
	// 所有时间戳（除了第一个）
	std::vector<int> deltas_;
	// 接收到第一个时间戳标记
	bool first_delta_flag_;
};

#endif
