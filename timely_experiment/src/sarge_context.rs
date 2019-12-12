
use timely::Data;
use std::clone::Clone;
use timely::ExchangeData;
use abomonation::Abomonation;

#[derive(Copy, Clone)]
pub struct SargeContext {
    pub source_replica: u64,
    pub dest_replica: u64,
    pub pipe_stage: u64,
    pub num_replicas: u64,
    pub num_rtcs: u64,
    pub is_rtc: bool,
}

unsafe_abomonate!(SargeContext : source_replica, dest_replica, pipe_stage, num_replicas, num_rtcs, is_rtc);
